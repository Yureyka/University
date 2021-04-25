<?php
/*
 * тест запрос к БД
 *
 * */

class Test extends Controller
{

    public function testic(){

        $model = new Post();
        $var = $model->find($_GET['id']);

        var_dump($var);
        die();
    }


}