<?php

class GuestBook
{
    public function guestsbook()
    {
        session_start();
        StatsAgent::saveStats();

        $filename = "message.inc";
        $file = fopen($filename, "a+");
        $model = new GuestsBook(UserFormValidator);
        $fileData = $model->readFile($file);

        if (!empty($_POST)) {

            $params = $_POST;

            $model->validate($params);

            $model->date = $model->setNowDate();
            $model->setSurname($params['surname']);
            $model->setName($params['name']);
            $model->setPatronymic($params['patronymic']);
            $model->setMail($params['e-mail']);
            $model->setFeedback($params['feedback']);

            $model->saveToFile($file);

        }
        $view = new View();
        $view->render("GuestsBook.php", "GuestsBook", $model, 'layout.php', ['fileData' => $fileData]);
        fclose($file);
    }
}