<?php


class GuestsBook extends Model
{
    protected $date;
    protected $surname;
    protected $name;
    protected $patronymic;
    protected $mail;
    protected $feedback;

    public function getDate()
    {
        return $this->date;
    }

    public function getSurname()
    {
        return $this->surname;
    }

    public function getName()
    {
        return $this->name;
    }

    public function setName($name)
    {
        $this->name = $name;
    }

    public function setSurname($surname)
    {
        $this->surname = $surname;
    }
    public function setPatronymic($patronymic)
    {
        $this->patronymic = $patronymic;
    }
    public function setMail($mail)
    {
        $this->mail = $mail;
    }
    public function setFeedback($feedback)
    {
        $this->feedback = $feedback;
    }

    public function getPatronymic()
    {
        return $this->patronymic;
    }

    public function getMail()
    {
        return $this->mail;
    }

    public function getFeedback()
    {
        return $this->feedback;
    }

    public function setNowDate()
    {
        $this->date = date('d.m.Y');
        return $this->date;
    }

    public function __construct($validator = null)
    {
        parent::__construct($validator);
    }

    public function readFile($file)
    {
        $contacts = [];

        while(!feof($file)){

            $fileString = fgets($file);

            if (empty($fileString)) {
                continue;
            }

            $arrayFileData = explode(";", $fileString);

            $temp = [
                'date' => trim($arrayFileData[0]),
                'fio' => trim($arrayFileData[1]),
                'mail' => trim($arrayFileData[2]),
                'feedback' => trim($arrayFileData[3])
            ];
            $contacts[] = $temp;
        }

        $contacts = $this->sortDate($contacts);

        return $contacts;
    }

    public function saveToFile($file){

        $string = $this->getDate() . ';' . $this->getSurname() . ' ' .  $this->getName() . ' ' . $this->getPatronymic() . ';' . $this->getMail() . ';' . $this->getFeedback() . "\r\n";

        fwrite($file, $string);
    }


    public function sortDate($array, $formatDate='d.m.Y')
    {
        uasort($array, function($first, $second) use ($formatDate) {
            $first = DateTime::createFromFormat($formatDate, $first['date']);
            $second = DateTime::createFromFormat($formatDate, $second['date']);

            return $first < $second;
        });

        return $array;
    }

}