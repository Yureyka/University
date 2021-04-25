<?php


class RegistrationController
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

                $user->fio = $params['name'];
                $user->mail = $params['e-mail'];
                $user->login = $params['login'];
                $user->password = $params['password'];


                $result = $user->findLogin($params['login']);

                $adUser = NULL;

                if($result != 0){
                    $adUser = 1;
                }else{
                    $adUser = 2;
                    $user->save();
                }
            }
        }

        $view = new View();
        $view->render("Registration.php", "Registration", $model = $userData, 'layout.php', $parameters = ['adUser' => $adUser]);
    }
}