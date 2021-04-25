<?php


class PostController extends Controller
{
    public function index()
    {
        $post = new Post();

        if (!empty($_GET['page'])) {

        }

        if (!empty($_POST)) {
            $params = $_POST;
            $post = new Post(UserFormValidator);
            $post->validate($params);

            if (empty($post->validator->errors)) {

                $post->theme = $params['theme'];
                $post->message = $params['feedback'];
                $post->dateTime = $post->setNowDate();

                if ($_FILES['photo']['type'] == "image/jpeg") {

                    $fileName = time() . $_FILES['photo']['name'];
                    $post->imageName = $fileName;

                    $fileTemp = $_FILES['photo']['tmp_name'];
                    move_uploaded_file($fileTemp, "../public/assets/userimage/" . $fileName);
                } else {
                    $post->imageName = "default.png";
                }

                $post->save();

            }
        }

        $tableData = $post->findAllDateDesc();
        $postsCount = count($post->findAllDateDesc());
        $pageCount = 5;
        $postsOnPage = ceil($postsCount / $pageCount);
        $numOfPages = ceil($postsCount / $postsOnPage);

        $paginationInfo = ['numOfPages' => $numOfPages, 'postsOnPage' => $postsOnPage, 'postsCount' => $postsCount];

        $pageNumber = isset($_GET['page']) ? $_GET['page'] : 1;
        $firstElement = ($pageNumber - 1) * $postsOnPage;
        $blogPostsArray = [];
        for ($i = $firstElement; $i < $firstElement + $postsOnPage; $i++) {
            array_push($blogPostsArray, $tableData[$i]);
        }
        $view = new View();
        $view->render("Post.php", "Edit blog", $model = $post, 'layout.php', $parameters = ['tableData' => $blogPostsArray, 'paginationInfo' => $paginationInfo]);
    }
}