<?php


class AdminController extends Controller
{
    public function index()
    {
        if (!empty($_POST)) {
            $params = $_POST;
            $password = '62cb1beb47a3c3cf885ee54bf4871f29';

            session_start();
            if ($params['login'] == 'admin' && md5($params['password']) == $password) {
                $_SESSION['isAdmin'] = true;
                header("Location: /admin/blogEditor");
            } else $_SESSION['isAdmin'] = false;
        }

        $isAdmin = $this->isAdmin();

        $view = new View();
        $view->render("index.php", "Login", $model = null, 'admin_layout.php', $parameters = ['isAdmin' => $isAdmin]);
    }

    public function isAdmin()
    {
        session_start();

        if (isset($_SESSION[isAdmin])) {
            if ($_SESSION[isAdmin]) {
                return true;
            } else return false;
        } else return false;
    }

    public static function logOut()
    {
        session_start();
        if (isset($_SESSION[isAdmin])) {
            unset($_SESSION[isAdmin]);
            header("Location: /admin/index");
        }
    }

    public function authenticate()
    {
        session_start();
        if (!isset($_SESSION[isAdmin])) {
            header("Location: /admin/index");
        }
    }

    public function feedback()
    {
        session_start();
        $this->authenticate();

        $model = new GuestsBook();

        if ($_FILES['feedback']['type'] == "text/plain") {

            if ($_FILES['feedback']['name'] == "message.inc") {
                $fileTemp = $_FILES['feedback']['tmp_name'];
                move_uploaded_file($fileTemp, "../public/message.inc");
            }
        }
        $view = new View();
        $view->render("Feedback.php", "Feedback", $model, 'admin_layout.php', []);
    }

    public function blogEditor()
    {
        session_start();
        $this->authenticate();

        $post = new Post();

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
        $view->render("PostEditor.php", "Edit blog", $model = null, 'admin_layout.php', $parameters = ['tableData' => $blogPostsArray, 'paginationInfo' => $paginationInfo]);
    }

    public function updatePost()
    {
        $post = new Post();

        $post->setId($_POST['editId']);
        $post->setTheme($_POST['editTheme']);
        $post->setMessage($_POST['editPostText']);

        $post->update();

        echo 1;
    }

    public function stats()
    {
        session_start();
        $this->authenticate();

        $statsData = new UserStats();
        $Data = $statsData->findAllDateDesc();
        $count = count($statsData->findAllDateDesc());
        $pageCount = 5;
        $recordsOnPage = ceil($count / $pageCount);
        $numOfPages = ceil($count / $recordsOnPage);

        $paginationInfo = ['numOfPages' => $numOfPages, 'recordsOnPage' => $recordsOnPage, 'count' => $count];

        $pageNumber = isset($_GET['page']) ? $_GET['page'] : 1;
        $firstElement = ($pageNumber - 1) * $recordsOnPage;
        $recordsArray = [];

        for ($i = $firstElement; $i < $firstElement + $recordsOnPage; $i++) {
            array_push($recordsArray, $Data[$i]);
        }

        $view = new View();
        $view->render("Statistics.php", "Statistics", $model = null, 'admin_layout.php', $parameters = ['statsData' => $recordsArray, 'paginationInfo' => $paginationInfo]);
    }
}