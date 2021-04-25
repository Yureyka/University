<?php

class Post extends Model
{
    protected $id;
    protected $theme;
    protected $imageName;
    protected $message;
    protected $dateTime;

    public function setId($id)
    {
        $this->id = $id;
    }

    public function getId()
    {
        return $this->id;
    }

    public function getTheme()
    {
        return $this->theme;
    }

    public function getImageName()
    {
        return $this->imageName;
    }

    public function getMessage()
    {
        return $this->message;
    }

    public function getDateTime()
    {
        return $this->dateTime;
    }

    public function setNowDate()
    {
        $this->dateTime = date('Y.m.d H:i:s');
        return $this->dateTime;
    }

    public function findAllDateDesc()
    {
        $query = sprintf(
            SqlBuilder::$selectQueryDateDesc,
            "*",
            static::$table,
            "dateTime"
        );
        $result = parent::execute($query, [], self::many_type);
        if (!$result) {
            echo "error!!!!";
        }

        return $result;
    }

    public function __construct($validator = null)
    {
        parent::__construct($validator);
        static::$table = "posts";
        parent::init();
    }
}