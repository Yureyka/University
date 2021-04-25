<?php


class TestController extends Controller
{
    public function index()
    {
        $testResult = NULL;
        if(!empty($_POST)) {
            $params = $_POST;

            $testResult = new TestResult(ResultsVerification);
            $testResult->validate($params);

            if (empty($errors)) {
                $testResult->validator->getTestResults($params);

                $testResult->name = $_POST['name'];
                $testResult->groupName = $_POST['group'];
                $testResult->firstAnswer = $_POST['ans1'];
                $testResult->secondAnswer = $_POST['ans2'];
                $testResult->thirdAnswer = $_POST['ans3'];
                $testResult->firstAnswerCorrectness = $testResult->validator->scores['ans1'];
                $testResult->secondAnswerCorrectness = $testResult->validator->scores['ans2'];
                $testResult->thirdAnswerCorrectness = $testResult->validator->scores['ans3'];
                $testResult->date = $testResult->setNowDate();

                $testResult->save();
            }
        }
        $view = new View();
        $view->render("test.php", "Test", $model = $testResult, 'layout.php', []);

    }
}