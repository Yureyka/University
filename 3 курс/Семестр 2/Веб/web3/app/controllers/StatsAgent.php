<?php


class StatsAgent
{
    public static function saveStats()
    {
        $usersStats = new UserStats();
        $usersStats->dateTime = $usersStats->setDateTime();
        $usersStats->webPage = $_SERVER["REQUEST_URI"];
        $usersStats->ip = $_SERVER["REMOTE_ADDR"];
        $usersStats->hostName = $_SERVER["SERVER_NAME"];
        $usersStats->browserName = $_SERVER["HTTP_USER_AGENT"];

        $usersStats->save();
    }
}