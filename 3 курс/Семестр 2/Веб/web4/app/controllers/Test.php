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

//        $strJson = "{\"response\":{\"result\":{\"code\":\"A3004\",\"description\":\"Ошибка получения данных\",\"execution_time\":\"0.0000\"},\"core\":\"localhost\"}}";
//        $strJson = '{"response":{"result":{"code":"A3004","description":"Ошибка получения данных","execution_time":"0.0000"},"core":"localhost"}}';
//
//        $jsonPretty = json_encode(json_decode($strJson), JSON_PRETTY_PRINT);
//        echo $jsonPretty;

    }


}