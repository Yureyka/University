<?php


class PhotoController extends Controller
{
    public function index()
    {
        $model = new Photo();

        $view = new View();
        $view->render("Photogallery.php", "Photo gallery", $model, 'layout.php', []);
    }

}