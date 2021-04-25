<?php
class Model extends BaseActiveRecord
{
    public $validator;

    function __construct($Validator = null)
    {
        if(!empty($Validator)){
            $this->validator = new $Validator;
        }
    }
    function validate($post_data)
    {
        $this->validator->validate($post_data);
    }
}