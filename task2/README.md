# Задание 2 Защита программ и данных
Мельников Лев СКБ16

## Программа 1
### Инструменты анализа

1. Retdec - для декомпиляции. Инструмент не справился с задачей.
Вывод декомпилированного текста generate\_pass
```
int64_t                                                                        _Z13generate_passNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(int64_t * result, int64_t a2) {
    int64_t result2 = (int64_t)result;
    int64_t v1 = __readfsqword(40); // 0x1026
    _ZNSaIcEC1Ev();
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_((char *   )result, &g1);
    _ZNSaIcED1Ev();
    int32_t v2 =                                                               _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv(); // 0x1070
    if (v2 > 0) {
        int32_t v3 = 0; // 0x10fb
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm(a2);

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc((char)result2);
        while (v3 + 1 != v2) {
            // 0x1086
            v3++;
            _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm(a2);

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc((char)result2);
        }
    }
    // 0x1138
    if (v1 != __readfsqword(40)) {
        // 0x1148
        __stack_chk_fail();
    }
    // 0x114d
    return result2;
}
```
2. Snowman. Лучше чем Retdec, но тоже не справился.
```
/* generate_pass(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) */
void _Z13generate_passNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(void* rdi, void* rsi) {
    void* rbp3;
    void* v4;
    void* v5;
    void* rdx6;
    uint64_t rax7;
    int32_t v8;
    int32_t v9;
    unsigned char* rax10;
    uint32_t eax11;
    int32_t edx12;
    int32_t edx13;
    uint64_t rax14;
    int32_t eax15;
    int64_t rsi16;

    rbp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v4 = rdi;
    v5 = rsi;
    fun_e00(reinterpret_cast<int64_t>(rbp3) - 37);
    rdx6 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rbp3) - 37);
    fun_e10(v4, 0x14f9, rdx6);
    fun_e20(reinterpret_cast<int64_t>(rbp3) - 37, 0x14f9, rdx6);
    rax7 = fun_e30(v5, 0x14f9, rdx6);
    v8 = *reinterpret_cast<int32_t*>(&rax7);
    v9 = 0;
    while (1) {
        if (v9 >= v8) 
            goto 0x1138;
        rax10 = fun_e40(v5, static_cast<int64_t>(v9));
        eax11 = *rax10;
        edx12 = (v9 + 17) * v8;
        edx13 = (edx12 << 8) - edx12 + *reinterpret_cast<signed char*>(&eax11);
        rax14 = edx13 * 0x1b4e81b5 >> 32;
        eax15 = edx13 - ((*reinterpret_cast<int32_t*>(&rax14) >> 3) - (edx13 >> 31)) * 75 + 48;
        *reinterpret_cast<int32_t*>(&rsi16) = *reinterpret_cast<signed char*>(&eax15);
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi16) + 4) = 0;
        fun_e50(v4, rsi16);
        ++v9;
    }
}
```
3. Ghidra. Полностью справился с задачей.
```
/* generate_pass(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>) */
    
basic_string_char_std__char_traits_char__std__allocator_char__ * generate_pass(basic_string param_1)
    
{   
  char *pcVar1;
  ulong in_RSI;
  undefined7 in_register_00000039;
  basic_string_char_std__char_traits_char__std__allocator_char__ *this;
  long in_FS_OFFSET;
  allocator_char_ local_2d;
  int local_2c;
  int local_28;
  int local_24;
  long local_20;

  this = (basic_string_char_std__char_traits_char__std__allocator_char__ *)
         CONCAT71(in_register_00000039,param_1);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::allocator<char>::allocator();
                    /* try { // try from 00101053 to 00101057 has its CatchHandler @ 00101104 */
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
            ((char *)this,(allocator *)&DAT_001014f9);
  std::allocator<char>::_allocator(&local_2d);
  local_28 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::length();
  local_2c = 0;
  while (local_2c < local_28) {
                    /* try { // try from 00101096 to 001010fa has its CatchHandler @ 0010111e */
    pcVar1 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     operator__(in_RSI);
    local_24 = ((local_2c + 0x11) * local_28 * 0xff + (int)*pcVar1) % 0x4b + 0x30;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator__
              (this,(char)local_24); 
    local_2c = local_2c + 1;
  }     
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }     
  return this;
}
```
4. IDA бесплатная версия - для анализа и запуска отладчика. (Скриншоты в папке images)
5. gdb - для отладки.

### Ход анализа
Сначала программой IDA была проанализирована логическая структура программы.
В этом помогли "зашитые" строки, которые запрашивают пароль, выдают
успех\неуспех. Потом были использованы разные декомпиляторы для восстановления
алгоритма формирования пароля. Результат дал только ghidra. По декомпилированному
коду был написан Keygen.
```
for (int i = 0; i < length; i++) {
        char current = username[i];
        int res = ((i + 0x11) * length * 0xff + current) % 0x4b + 0x30;
        output += static_cast<char>(res);
    }   
```
С помощью Snowman также разобрана сама логика программы.
1. Она запрашивает логин\пароль.
2. Логин передается в функцию generate_pass.
3. Generate pass генерирует пароль на основе логина
4. логин, пароль и функция сравнения передаются в функию check. В качестве сравнения используется strcmp.
5. Функция check выполняет сравнение и "выдает" или "блокирует" доступ.

### Патчинг
Для патча была выбрана замена аргумента функции check. Патч приводит к тому, что в функцию первым
и вторым аргументом передается одна и та же строка, что приводит к инвариантному срабатыванию
функции strcmp.


## Программа 2
### Анализ
Программа 2 была проанализирована на основе исходного текста, который был вручную отформатирован.
В результате была выявлена следующая логика.

1. Програма пораждает процесс.
2.1. Дочерний процесс:
2.2. Запрашивает логин пароль
2.3. Вызывает функцию генерации пароля по логину, который
 зависит от pid,  и euid.
2.4. Сгенерированный пароль и введенный сравниваются
2.5. Результат сравнения передается в код завершения процесса
3.1. Родительский процесс
3.2. Дожидается смерти дочернего.
3.3. На основе кода завершения дочернего процесса выдается или запрещается доступ

### Подходы к атаке
1. Копирование процедуры генерации пароля и её реализация в виде keygen.
Keygen будет иметь 3 параметра, логин, pid, euid.
2. Патчинг места проверки кода завершения дочернего процесса.

