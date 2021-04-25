<?php


class PageController extends Controller
{
    public function main()
    {
        session_start();
        StatsAgent::saveStats();

        $view = new View();
        $view->render("index.php", "Main", []);
    }

    public function about()
    {
        session_start();
        StatsAgent::saveStats();

        $view = new View();
        $view->render("About_me.php", "About me", []);
    }

    public function interests()
    {
        session_start();
        StatsAgent::saveStats();

        $view = new View();
        $view->render("My_hobbies.php", "My interests", []);
    }

    public function study()
    {
        session_start();
        StatsAgent::saveStats();

        $view = new View();
        $view->render("My_study.php", "Study", []);
    }

    public function history()
    {
        include_once "../app/views/History.html";
    }
}