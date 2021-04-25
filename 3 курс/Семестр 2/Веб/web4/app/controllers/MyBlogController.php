<?php


class MyBlogController extends Controller
{
    public function index()
    {
        session_start();
        StatsAgent::saveStats();

        $post = new Post();

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
        $view->render("MyBlog.php", "My blog", $model = $post, 'layout.php', $parameters = ['tableData' => $blogPostsArray, 'paginationInfo' => $paginationInfo]);
    }

    public function addComment()
    {
        session_start();

        header("Access-Control-Allow-Origin: *");
        $var = new SimpleXMLElement(file_get_contents('php://input'));
        $commentArray = (array)$var;

        if(!empty($commentArray)){
            $comment = new Comment();

            $comment->author = $_SESSION['userId'];
            $comment->dateTime = $comment->setNowDate();
            $comment->comment = $commentArray['commentText'];
            $comment->postId = $commentArray['idBlog'];

            $comment->save();

            echo 1;
        }
    }
}