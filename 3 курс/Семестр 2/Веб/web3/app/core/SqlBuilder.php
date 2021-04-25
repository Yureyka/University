<?php

class SqlBuilder {
    public static $deleteQuery =       'DELETE FROM `%s` WHERE id=?';
    public static $deleteAll =          'DELETE FROM `%s`';
    public static $insertQuery =       'INSERT INTO `%s` (%s) VALUES (%s)';
    public static $selectQuery =       'SELECT %s FROM `%s`';
    public static $selectQueryById =       'SELECT %s FROM `%s` WHERE id=?';
    public static $selectQueryByLogin =     'SELECT %s FROM `%s` WHERE login=?';
    public static $selectQueryByUserData =  'SELECT %s FROM `%s` WHERE login=? AND password=?';
    public static $updateQuery =       'UPDATE `%s` SET %s WHERE id=?';
    public static $selectQueryDateDesc =  'SELECT %s FROM `%s` ORDER BY %s DESC';

    public static function deleteAll($tableName){
        return sprintf(
            SqlBuilder::$deleteAll,
            $tableName
        );
    }

    public static function buildSelectQuery($from, $select = '*', $where = [], &$args = []) {
        $query = sprintf(self::$selectQuery, $select, $from);

        if ( !empty($where) ) {
            $query .= self::buildWherePartQuery($where, $args);
        }

        return $query;
    }

    public static function buildWherePartQuery($params, &$whereValues = []) {
        $where = ' WHERE';

        foreach( $params as $column => $value ) {
            $where .= ' ' . $column . '=? AND';
            $whereValues[] = $value;
        }

        return rtrim($where, 'AND');
    }
}