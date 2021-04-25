<?php


class RegistrationController
{
    public function index()
    {
        session_start();
        StatsAgent::saveStats();

        $userData = NULL;
        if (!empty($_POST)) {
            $params = $_POST;
            $userData = new User(UserFormValidator);
            $userData->validate($params);

            if (empty($userData->validator->errors)) {
                $user = new User();

                $user->fio = $params['name'];
                $user->mail = $params['e-mail'];
                $user->login = $params['login'];
                $user->password = $params['password'];

                $result = $user->findLogin($params['login']);

                if ($result == 0) {
                    $user->save();
                    header("Location: /authorization/index");
                } else {

                }
            }
        }

        $view = new View();
        $view->render("Registration.php", "Registration", $model = $userData, 'layout.php', []);
    }

    public function checkLogin()
    {
        header("Access-Control-Allow-Origin: *");
        $var = json_decode(file_get_contents('php://input'));
        $user = new User();
        if ($user->findLogin($var->login) == 0) {
            echo 0;
        } else echo 1;
    }
}