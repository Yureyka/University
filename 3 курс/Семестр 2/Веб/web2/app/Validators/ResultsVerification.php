<?php

class ResultsVerification extends CustomFormValidator
{
    public $name;
    public $cycleCheck;
    public $cycleRadio;
    public $cycleSelect;

public $scores = [
'numOfCorrectAns' => 0,
'ans1' => 'Неверно',
'ans2' => 'Неверно',
'ans3' => 'Неверно'
];

    public function __construct()
    {
        $this->rules = [
            "name" => [
                "isNotEmpty"
            ]
        ];

        parent::__construct();
    }

    public function validate($postArray)
    {
        foreach ($postArray as $field => $value) {
            if (!empty($this->rules[$field])) {
                foreach ($this->rules[$field] as $name => $rule) {
                    $this->$rule($value, $field);
                }
            }
        }
    }

    public function getTestResults($postArray)
    {
        $this->name = $postArray["name"];
        $this->cycleCheck = $postArray["ans1"];
        $this->cycleRadio = $postArray["ans3"];
        $this->cycleSelect = $postArray["ans2"];

        if ($this->cycleCheck == "гигантские") {
            $this->scores['ans1'] = "Верно";
            $this->scores['numOfCorrectAns']++;
        }
        if ($this->cycleSelect == "4") {
            $this->scores['ans2'] = "Верно";
            $this->scores['numOfCorrectAns']++;
        }
        if ($this->cycleRadio == "Утомление") {
            $this->scores['ans3'] = "Верно";
            $this->scores['numOfCorrectAns']++;
        }

        return $this->scores;
    }
}