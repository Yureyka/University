<?php


class ContactController extends Controller
{
    public function index()
    {
        session_start();
        StatsAgent::saveStats();

        if(!empty($_POST)){
            $params = $_POST;
        }
        $model = new Model(UserFormValidator);
        $model->validate($params);

        $view = new View();
        $view->render("Contacts.php", "Contacts", $model, 'layout.php', []);
    }
}