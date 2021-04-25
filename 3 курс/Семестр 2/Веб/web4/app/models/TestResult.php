<?php


class TestResult extends Model
{
    protected $id;
    protected $name;
    protected $date;
    protected $groupName;
    protected $firstAnswer;
    protected $secondAnswer;
    protected $thirdAnswer;
    protected $firstAnswerCorrectness;
    protected $secondAnswerCorrectness;
    protected $thirdAnswerCorrectness;

    public function getId()
    {
        return $this->id;
    }

    public function getName()
    {
        return $this->name;
    }

    public function getDate()
    {
        return $this->date;
    }

    public function setNowDate()
    {
        $this->date = date('y.m.d');
        return $this->date;
    }

    public function getGroupName()
    {
        return $this->groupName;
    }

    public function getFirstAnswer()
    {
        return $this->firstAnswer;
    }

    public function getSecondAnswer()
    {
        return $this->secondAnswer;
    }

    public function getThirdAnswer()
    {
        return $this->thirdAnswer;
    }

    public function getFirstAnswerCorrectness()
    {
        return $this->firstAnswerCorrectness;
    }

    public function getSecondAnswerCorrectness()
    {
        return $this->secondAnswerCorrectness;
    }

    public function getThirdAnswerCorrectness()
    {
        return $this->thirdAnswerCorrectness;
    }

    public function findTestResults()
    {
        $query = sprintf(
            SqlBuilder::$selectQuery,
            "*",
            static::$table
        );
        $result = parent::execute($query, [], self::many_type);
        if (!$result) {
            return 0;
        }
        return $result;
    }

    public function __construct($validator = null)
    {
        parent::__construct($validator);
        static::$table = "testrezults";
        parent::init();
    }
}