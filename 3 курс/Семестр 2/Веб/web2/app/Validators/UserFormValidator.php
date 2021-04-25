<?php
/**
 * Created by PhpStorm.
 * User: -
 * Date: 17.03.2019
 * Time: 14:36
 */

class UserFormValidator extends FormValidator
{
    public function __construct()
    {
        $this->rules = [
            "name" => [
                "isNotEmpty"
            ],
            "surname" =>[
                "isNotEmpty"
            ],
            "patronymic" =>[
                "isNotEmpty"
            ],
            "feedback" =>[
                "isNotEmpty"
            ],
            "sex" => [
                "isNotEmpty"
            ],
            "phone" => [
                "isNotEmpty",
                "isNumber"
            ],
            "e-mail" => [
                "isNotEmpty",
                "isEmail"
            ],
            "message" => [
                "isNotEmpty"
            ],
            "theme" => [
                "isNotEmpty"
            ],
            "e-mailR" => [
                "isNotEmpty",
                "isEmail"
            ]
        ];

        parent::__construct();
    }

    public function validate($postArray)
    {
        foreach ($postArray as $field => $value) {
            if (!empty($this->rules[$field])) {
                foreach ($this->rules[$field] as $name => $rule) {
                    if ($rule == "isNotEmpty") {
                        if ($this->$rule($value, $field)) {
                            break;
                        }
                    } else {
                        $this->$rule($value, $field);
                    }
                }
            }
        }
    }
}