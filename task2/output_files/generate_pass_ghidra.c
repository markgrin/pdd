
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

