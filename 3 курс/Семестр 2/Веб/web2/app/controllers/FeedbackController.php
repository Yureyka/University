<?php

class FeedbackController extends Controller
{
    public function index()
    {
        $model = new GuestsBook();

        if ($_FILES['feedback']['type'] == "text/plain") {

            if($_FILES['feedback']['name'] == "message.inc"){
                $fileTemp = $_FILES['feedback']['tmp_name'];
                move_uploaded_file($fileTemp, "../public/message.inc");
            }
        }
        $view = new View();
        $view->render("Feedback.php", "Feedback", $model, 'layout.php', []);
    }
}