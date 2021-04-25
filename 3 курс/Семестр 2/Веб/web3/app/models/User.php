<?php


class User extends Model
{
    protected $fio;
    protected $mail;
    protected $login;
    protected $password;

    public function getFio()
    {
        return $this->fio;
    }

    public function getMail()
    {
        return $this->mail;
    }

    public function getLogin()
    {
        return $this->login;
    }

    public function getPassword()
    {
        return $this->password;
    }

    public function findLogin($login)
    {
        $query = sprintf(
            SqlBuilder::$selectQueryByLogin,
            "*",
            static::$table
        );
        $result = parent::execute($query, [$login], self::single_type);
        if (!$result) {
            return 0;
        }
        return $result;
    }

    public function findUser($login, $password)
    {
        $query = sprintf(
            SqlBuilder::$selectQueryByUserData,
            "*",
            static::$table
        );
        $result = parent::execute($query, [$login, $password], self::single_type);
        if (!$result) {
            return 0;
        }
        return $result;
    }

    public function __construct($validator = null)
    {
        parent::__construct($validator);
        static::$table = "users";
        parent::init();
    }
}