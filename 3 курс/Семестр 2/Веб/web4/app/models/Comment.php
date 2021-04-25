<?php


class Comment extends Model
{
    protected $id;
    protected $dateTime;
    protected $author;
    protected $comment;
    protected $postId;

    public function getId()
    {
        return $this->id;
    }

    public function getAuthor()
    {
        return $this->author;
    }

    public function getComment()
    {
        return $this->comment;
    }

    public function getDateTime()
    {
        return $this->dateTime;
    }

    public function getPostId()
    {
        return $this->postId;
    }

    public function setNowDate()
    {
        $this->dateTime = date('Y.m.d H:i:s');
        return $this->dateTime;
    }

    public function findAllComment($postId)
    {
        $query = sprintf(
            SqlBuilder::$selectQueryByCommentId,
            "*",
            static::$table
        );
        $result = parent::execute($query, [$postId], self::many_type);
        if (!$result) {
            return 0;
        }
        return $result;
    }


    public function findUserComments($postId)
    {
        $on = "author = users.id";
        $query = sprintf(
            SqlBuilder::$selectQueryByUserComments,
            "*",
            static::$table,
            "users",
            $on
        );
        $result = parent::execute($query, [$postId], self::many_type);

        if (!$result) {
            return 0;
        }
        return $result;
    }

    public function __construct($validator = null)
    {
        parent::__construct($validator);
        static::$table = "comments";
        parent::init();
    }
}