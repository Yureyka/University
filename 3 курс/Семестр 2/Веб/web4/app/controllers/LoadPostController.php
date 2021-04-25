<?php


class LoadPostController extends Controller
{
    public function index()
    {
        session_start();
        StatsAgent::saveStats();

        $filename = $_FILES['record']['tmp_name'];
        $file = fopen($filename, "r+");

        if ($_FILES['record']['type'] == "application/vnd.ms-excel") {

            while (!feof($file)) {
                $fileString = fgetcsv($file, 512, ';', '"');

                if(!empty($fileString)) {

                    $post = new Post();

                    $post->theme = $fileString[0];
                    $post->message = $fileString[1];
                    $post->dateTime = $fileString[3];
                    $post->imageName = "default.png";

                    $post->save();
                }
            }
        }
        $view = new View();
        $view->render("PostLoader.php", "Post loader", $model = $post, 'layout.php', []);
//        fclose($file);
    }
}