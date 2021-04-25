<?php


class FormValidator
{
    public $rules = [];
    public $errors = [];

    public function __construct() {
    }

    public function isNotEmpty($data, $field = "")
    {
        if (empty($data)) {
            $this->errors[] = "Field: " . $field . " can not be empty.";
            return 1;
        };

        return 0;
    }

    public function isNumber($data, $field = "")
    {
        if (!preg_match('/((8|\+7)-?)?\(?\d{3,5}\)?-?\d{1}-?\d{1}-?\d{1}-?\d{1}-?\d{1}((-?\d{1})?-?\d{1})?/', $data)) {
            $this->errors[] = "Field: " . $field . " is not correct.";
        }
    }

    public function isLess($data, $value)
    {
        return ($data < $value);
    }

    public function isGreater($data, $value)
    {
        return ($data > $value);
    }

    public function isEmail($data, $field = "")
    {
        if (!filter_var($data, FILTER_VALIDATE_EMAIL)) {
            $this->errors[] = "Field: " . $field . " is not correct.";
        };
    }



    public function setRule($fieldName, $validatorName)
    {
        $this->rules[$fieldName][] = $validatorName;
    }

    public function loginExist()
    {
        $this->errors[] = "Field Login is already exist .";
    }

    public function validate($postArray)
    {

    }

    public function showErrors()
    {
        return $this->errors;
    }

}
