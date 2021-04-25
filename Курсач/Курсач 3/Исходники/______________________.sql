-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1:3306
-- Время создания: Дек 06 2019 г., 00:13
-- Версия сервера: 10.3.13-MariaDB-log
-- Версия PHP: 7.1.32

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `турагенство`
--

-- --------------------------------------------------------

--
-- Структура таблицы `клиент`
--

CREATE TABLE `клиент` (
  `ID_клиента` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Количество_персон` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Количество_детей` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Паспорт` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ФИО_клиента` varchar(40) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Телефон_клиента` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `возврат`
--

CREATE TABLE `возврат` (
  `ID_возврата` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Дата_возврата` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Причина_возврата` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Сумма_возврата` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_тура` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_клиента` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_сотрудника` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `отель`
--

CREATE TABLE `отель` (
  `ID_отеля` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Название_отеля` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Адрес_отеля` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Класс_отеля` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `скидки`
--

CREATE TABLE `скидки` (
  `ID_скидки` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Размер_скидки` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `сводка_продаж`
--

CREATE TABLE `сводка_продаж` (
  `ID_сводки` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Количество_продаж` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_сотрудника` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `сотрудник`
--

CREATE TABLE `сотрудник` (
  `ID_сотрудника` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ФИО_сотрудника` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Телефон_сотрудника` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Структура таблицы `тур`
--

CREATE TABLE `тур` (
  `ID_тура` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Вид_тура` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Стоимость_тура` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Дата_отправления` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Длительность_тура` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_отеля` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_клиента` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ID_скидки` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `клиент`
--
ALTER TABLE `клиент`
  ADD PRIMARY KEY (`ID_клиента`);

--
-- Индексы таблицы `возврат`
--
ALTER TABLE `возврат`
  ADD PRIMARY KEY (`ID_возврата`),
  ADD KEY `ID_тура` (`ID_тура`),
  ADD KEY `ID_клиента` (`ID_клиента`),
  ADD KEY `ID_сотрудника` (`ID_сотрудника`);

--
-- Индексы таблицы `отель`
--
ALTER TABLE `отель`
  ADD PRIMARY KEY (`ID_отеля`);

--
-- Индексы таблицы `скидки`
--
ALTER TABLE `скидки`
  ADD PRIMARY KEY (`ID_скидки`);

--
-- Индексы таблицы `сводка_продаж`
--
ALTER TABLE `сводка_продаж`
  ADD PRIMARY KEY (`ID_сводки`),
  ADD KEY `ID_сотрудника` (`ID_сотрудника`);

--
-- Индексы таблицы `сотрудник`
--
ALTER TABLE `сотрудник`
  ADD PRIMARY KEY (`ID_сотрудника`);

--
-- Индексы таблицы `тур`
--
ALTER TABLE `тур`
  ADD PRIMARY KEY (`ID_тура`),
  ADD KEY `ID_отеля` (`ID_отеля`),
  ADD KEY `ID_клиента` (`ID_клиента`),
  ADD KEY `ID_скидки` (`ID_скидки`);

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `возврат`
--
ALTER TABLE `возврат`
  ADD CONSTRAINT `возврат_ibfk_1` FOREIGN KEY (`ID_тура`) REFERENCES `тур` (`ID_тура`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `возврат_ibfk_2` FOREIGN KEY (`ID_клиента`) REFERENCES `клиент` (`ID_клиента`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `возврат_ibfk_3` FOREIGN KEY (`ID_сотрудника`) REFERENCES `сотрудник` (`ID_сотрудника`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `сводка_продаж`
--
ALTER TABLE `сводка_продаж`
  ADD CONSTRAINT `сводка_продаж_ibfk_1` FOREIGN KEY (`ID_сотрудника`) REFERENCES `сотрудник` (`ID_сотрудника`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `тур`
--
ALTER TABLE `тур`
  ADD CONSTRAINT `тур_ibfk_1` FOREIGN KEY (`ID_отеля`) REFERENCES `отель` (`ID_отеля`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `тур_ibfk_2` FOREIGN KEY (`ID_клиента`) REFERENCES `клиент` (`ID_клиента`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `тур_ibfk_3` FOREIGN KEY (`ID_скидки`) REFERENCES `скидки` (`ID_скидки`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
