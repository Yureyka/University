<?php


class Router
{
    public function handle()
    {
        try {

            $controller = null;
            $actionName = "init";

            $routes = explode('/', $_SERVER['REQUEST_URI']);

            $controllerName = $routes[1];
            if (!empty($controllerName)) {
                $controller = $this->getController($controllerName);
            }
            if (!empty($routes[2])) {
                if (strpos($routes[2], "?")) {
                    $actionName = substr($routes[2], 0, strpos($routes[2], "?"));
                } else {
                    $actionName = $routes[2];
                }
            }
            $controller->$actionName();
        } catch (Exception $e) {
            var_dump($e->getMessage());
            Router::ErrorPage404();
        }
    }

    public function __autoload($ClassName)
    {
        var_dump($ClassName);
        include_once "../controllers/". $ClassName .".php";
    }

    private function getController($route)
    {
        switch($route){
            case 'page':
                return new PageController();
                break;
            case 'photo':
                return new PhotoController();
                break;
            case 'test':
                return new TestController();
                break;
            case 'contacts':
                return new ContactController();
                break;
            case 'guestsbook':
                return new GuestBook();
                break;
            case 'blog':
                return new MyBlogController();
                break;
            case 'blogpost':
                return new PostController();
                break;
            case 'feedback':
                return new FeedbackController();
                break;
            case 'postloader':
                return new LoadPostController();
                break;

            case 'testic': //тестовый контроллер
                return new Test();
                break;

            default: throw new Exception("Not found", 404);

        }
    }
    public function ErrorPage404(){
        echo '<script type="text/javascript">';
        echo 'window.location.href="404.php";';
        echo '</script>';
    }
}