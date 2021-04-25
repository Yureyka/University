<?php
class View
{
    /**

     * @param array $parameters
     */
    function render($contentView, $title, $model = NULL, $layout = 'layout.php', $parameters = [])
    {
        include '../app/views/'.$layout;
    }
}