<?php


class AuthorizationController extends Controller
{
    public function index()
    {
        session_start();
        StatsAgent::saveStats();

        $userData = NULL;
        if(!empty($_POST)) {
            $params = $_POST;
            $userData = new User(UserFormValidator);
            $userData->validate($params);

            if(empty($userData->validator->errors)){
                $user = new User();

                $user->login = $params['login'];
                $user->password = $params['password'];

                $result = $user->findUser($params['login'], $params['password']);
                $existUser = NULL;

                if($result != 0){
                    $_SESSION['isUser'] = true;

                    $_SESSION['userName'] = $result['fio'];
                    header("Location: /blog/index");
                }else{
                    header("Location: /authorization/index");
                    $_SESSION['isUser'] = false;
                }
            }
        }

        $view = new View();
        $view->render("Authorization.php", "Authorization", $model = $userData, "layout.php", $parameters = ['existUser' => $existUser]);
    }

    public function isUser()
    {
        session_start();

        if (isset($_SESSION[isUser])) {
            if ($_SESSION[isUser]) {
                return true;
            } else return false;
        } else return false;
    }

    public static function logOut()
    {
        session_start();

        if (isset($_SESSION[isUser])) {
            unset($_SESSION[isUser]);
            header("Location: /authorization/index");
        }
    }
}