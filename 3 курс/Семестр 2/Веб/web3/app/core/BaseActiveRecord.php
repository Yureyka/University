<?php

/**
 * Created by PhpStorm.
 * User: -
 * Date: 05.04.2020
 * Time: 10:48
 */
abstract class BaseActiveRecord
{
    /**
     * @var $pdo PDO
     */
    public static $pdo;
    public static $table;
    private $modified = false;
    private $fields = [];
    private $loaded = false;
    private $id = null;

    const single_type = 'single';
    const many_type = 'many type';

    protected static function execute($query, $args = [], $type = null)
    {
        $query = static::$pdo->prepare($query);

        $query->execute($args);

        if ($type == self::single_type) {
            return $query->fetch(PDO::FETCH_ASSOC);
        } else if ($type == self::many_type) {

            return $query->fetchAll(PDO::FETCH_ASSOC);
        }
    }

    public function deleteAll()
    {
        $query = SqlBuilder::deleteAll(static::$table);
        self::execute($query);
    }

    private function load()
    {
        if ($this->id == NULL || $this->loaded) {
            return false;
        }

        $queryArgs = [];
        $query = SqlBuilder::buildSelectQuery($this->table, '*', ['id' => $this->id], $queryArgs);
        $params = self::execute($query, $queryArgs, 'single');

        foreach ($params as $column => $value) {
            $this->fields[$column] = $value;
        }

        $this->modified = false;
        $this->loaded = true;

        return true;
    }

    public function __get($name)
    {
        if ($this->modified) {
            throw new InvalidOperationException;
        }

        $getMethod = 'get' . ucfirst($name);
        if (method_exists($this, $getMethod)) {
            return $this->$getMethod();
        }

        $this->load();

        return $this->getValue($name);
    }

    public function __set($name, $value)
    {
        $value = str_replace("'", "''", $value);
        $this->setValue($name, $value);
    }

    public function getValue($name)
    {
        $this->load();

        if ($name == 'id') {
            return $this->id;
        }

        return $this->fields[$name];
    }

    public function setValue($name, $value)
    {
        $this->fields[$name] = $value;
        $this->modified = true;

    }


    public function init()
    {
        $dsn = 'mysql:dbname=laba;host=127.0.0.1';
        $username = 'root';
        $password = '';
        try {
            static::$pdo = new PDO(
                $dsn, $username, $password,
                [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]
            );
        } catch (PDOException $e) {
            echo 'Подключение не удалось: ' . $e->getMessage();
        }

    }

    public function find($id)
    {
        $query = sprintf(
            SqlBuilder::$selectQueryById,
            "*",
            static::$table
        );

        $result = self::execute($query, [$id], self::single_type);
        if (!$result) {
            echo "error!!!!";
        }

        return $result;
    }

    public function delete()
    {

        $query = sprintf(
            SqlBuilder::$deleteQuery,
            static::$table,
            $this->id
        );

        self::execute($query);
    }

    public function save()
    {
        if ($this->id) {
            $this->update();
        } else {
            $this->insert();
        }
    }

    private function insert()
    { // modify this method
        $fieldsStr = '';
        $valuesStr = '';
        foreach ($this->fields as $field => $value) {
            $fieldsStr .= $field . ",";
            $valuesStr .= "'" . $value . "',";
        }
        $fieldsStr = rtrim($fieldsStr, ",");
        $valuesStr = rtrim($valuesStr, ",");
        $query = sprintf(
            SqlBuilder::$insertQuery,
            static::$table,
            $fieldsStr,
            $valuesStr
        );
        self::execute($query);

        $this->loaded = true;
    }

    private function update()
    {
        $modifiedFieldsStr = '';
        foreach ($this->fields as $field => $value) {
            $modifiedFieldsStr .= $field . "='" . $value . "',";
        }
        $modifiedFieldsStr = rtrim($modifiedFieldsStr, ",");
        $query = sprintf(SqlBuilder::$updateQuery, $this->table, $modifiedFieldsStr);
        self::execute($query, array($this->id));
    }


}