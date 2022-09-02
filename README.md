# ft_printf
This is reproduction of an original <code>int printf(const char *str, ...)</code> from <b>stdio.h</b>.

<h2>Signature</h2>
<code>int ft_printf(const char *str, ...)</code>

<ul>
  <li> <code>str</code> is a string that will be displayed.
  <li> <code>...</code> represents indefinite number of arguments that can be passed. More about arguments format: <a href="https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm"> Arguments format</a>.
  <li> The function returns the number of characters printed.
</ul>

<h2>Examle</h2>
<p><code>const char* name = "Andrii Antropov";</code><br>
<code>ft_printf("My name is %s", name);</code></p>
<p><b>Output:</b> My name is Andrii Antropov.</p>
