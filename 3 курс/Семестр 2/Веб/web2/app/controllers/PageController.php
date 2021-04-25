<?php


class PageController extends Controller
{
    public function main()
    {
        //include_once "../app/views/index.php";

        $view = new View();
        $view->render("index.php", "Main", []);


    }

    public function about()
    {
        $view = new View();
        $view->render("About_me.php", "About me", []);
    }

    public function interests()
    {

        $view = new View();
        $view->render("My_hobbies.php", "My interests", []);
    }

    public function study()
    {
//        include_once "../app/views/My_study.php";
        $view = new View();
        $view->render("My_study.php", "Study", []);
    }

    public function history()
    {
        include_once "../app/views/History.html";
    }
}