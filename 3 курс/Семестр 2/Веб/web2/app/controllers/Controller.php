<?php


class Controller{
    public function init()
    {
        echo "Page not found";
    }

    public function __call($name, $arg)
    {
        echo "It did not work, unfortunately";
    }


}
