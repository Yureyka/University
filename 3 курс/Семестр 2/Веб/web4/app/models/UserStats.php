<?php


class UserStats extends Model
{
    protected $dateTime;
    protected $webPage;
    protected $ip;
    protected $hostName;
    protected $browserName;

    public function getDateTime()
    {
        return $this->dateTime;
    }

    public function getWebPage()
    {
        return $this->webPage;
    }

    public function getIp()
    {
        return $this->ip;
    }

    public function getHostName()
    {
        return $this->hostName;
    }

    public function getBrowserName()
    {
        return $this->browserName;
    }

    public function setDateTime()
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
        static::$table = "usersstats";
        parent::init();
    }

}