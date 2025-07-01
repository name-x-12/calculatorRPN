<h1 align="center">Калькулятор обратной польской записи (RPN)</h1>

<p align="center">
  <strong>Автор:</strong> Тараканов Антон (ИТ-12)<br>
</p>

<h2>Описание проекта</h2>
<p>Программа вычисляет математические выражения, записанные в <strong>обратной польской записи (постфиксной записи)</strong>. Основное преимущество RPN — отсутствие необходимости в скобках и четкие правила вычислений.</p>

<details>
<summary><b>▸ Как это работает</b></summary>

<p>Программа использует <strong>стековую структуру данных</strong> для хранения промежуточных результатов.</p>

<p><strong>Пример вычисления выражения "3 4 + 5 *":</strong></p>
<ol>
  <li>Число <code>3</code> помещается в стек</li>
  <li>Число <code>4</code> помещается в стек</li>
  <li>Оператор <code>+</code> извлекает <code>4</code> и <code>3</code>, складывает их (<code>7</code>) и кладет результат обратно</li>
  <li>Число <code>5</code> помещается в стек</li>
  <li>Оператор <code>*</code> извлекает <code>5</code> и <code>7</code>, перемножает их (<code>35</code>) и возвращает в стек</li>
  <li>Результат <code>35</code> выводится на экран</li>
</ol>
</details>

<details>
<summary><b>▸ Особенности реализации</b></summary>
<ul>
  <li>Полностью самостоятельная реализация стека (без использования STL stack)</li>
  <li>Поддержка вещественных чисел (<code>3.14</code>, <code>0.5</code>, <code>.25</code>)</li>
  <li>Обработка отрицательных чисел (<code>-2.5</code>)</li>
  <li>Детальные сообщения об ошибках:
    <ul>
      <li>Деление на ноль</li>
      <li>Недостаток операндов</li>
      <li>Некорректные символы</li>
      <li>Лишние числа в выражении</li>
    </ul>
  </li>
</ul>
</details>

<details>
<summary><b>▸ Примеры выражений</b></summary>

<p><strong>Простые операции:</strong></p>
<table>
  <tr>
    <td><code>3 4 +</code></td>
    <td>→</td>
    <td><code>7</code></td>
  </tr>
  <tr>
    <td><code>10 5 -</code></td>
    <td>→</td>
    <td><code>5</code></td>
  </tr>
  <tr>
    <td><code>3 4 *</code></td>
    <td>→</td>
    <td><code>12</code></td>
  </tr>
  <tr>
    <td><code>20 4 /</code></td>
    <td>→</td>
    <td><code>5</code></td>
  </tr>
</table>

<p><strong>Сложные выражения:</strong></p>
<table>
  <tr>
    <td><code>15 7 1 1 + - / 3 *</code></td>
    <td>→</td>
    <td><code>15</code></td>
    <td>(эквивалент <code>(15/(7-(1+1)))*3</code>)</td>
  </tr>
  <tr>
    <td><code>5 1 2 + 4 * +</code></td>
    <td>→</td>
    <td><code>17</code></td>
    <td>(эквивалент <code>5+(1+2)*4</code>)</td>
  </tr>
</table>
</details>

<details>
<summary><b>▸ Обработка ошибок</b></summary>
<p>Программа обнаружит и сообщит о:</p>
<ul>
  <li>Неправильном формате чисел</li>
  <li>Нехватке чисел для операций</li>
  <li>Делении на ноль</li>
  <li>Лишних числах в выражении</li>
  <li>Недопустимых символах</li>
</ul>

<p><strong>Примеры сообщений об ошибках:</strong></p>
<pre>ОШИБКА: Недостаточно операндов для операции '+'
Входные данные: "5 +"</pre>

<pre>ОШИБКА: Деление на ноль
Входные данные: "4 0 /"</pre>
</details>

<details>
<summary><b>▸ Установка и использование</b></summary>
<h3>Требования</h3>
<ul>
  <li>Компилятор C++ (g++ или clang)</li>
  <li>CMake версии 3.10 и выше</li>
</ul>

<h3>Сборка</h3>
<pre><code>git clone https://github.com/ваш-репозиторий/rpn-calculator.git
cd rpn-calculator
mkdir build && cd build
cmake ..
make</code></pre>

<h3>Запуск</h3>
<pre><code>./rpn_calculator
Введите выражение в RPN: 3 4 + 5 *
Результат: 35</code></pre>
</details>



