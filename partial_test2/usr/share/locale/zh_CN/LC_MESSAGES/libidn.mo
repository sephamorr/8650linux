��    :      �  O   �      �  �   �  c   �  �   �  a   �  K   �  �   4  '  1     Y	     p	  *   	  �  �	  -   �  &   �     �  .     )   5  )   _  -   �  I   �               .  "   <      _  &   �  -   �  -   �          #  #   3  6   W     �     �     �     �     �  &   �  O     -   k     �     �  #   �  "   �  %   �  "   $  %   G     m     �     �     �     �  5   �               +     B     b  u  s  �   �  b   �  �   �  k   �  D   �  
  1    <     L     _     u  �  �  *   S  #   ~     �  +   �  *   �  (     )   >  =   h     �     �     �     �  )   �     "  $   8  '   ]     �     �  #   �  7   �          &     <     C     X  .   l  +   �  %   �     �     �  &        7     Q     n     �     �     �     �     �       6   	     @     T     i     �     �     6       )      -   &                     (   *   7                      0   :         "   
          $           8   3                              2          +   1          4              /                     9   !                    5   #   %   	      ,   '                .              --allow-unassigned   Toggle IDNA AllowUnassigned flag (default off)
      --usestd3asciirules  Toggle IDNA UseSTD3ASCIIRules flag (default off)
       --debug              Print debugging information
      --quiet              Silent operation
       --no-tld             Don't check string for TLD specific rules
                             Only for --idna-to-ascii and --idna-to-unicode
   -h, --help               Print help and exit
  -V, --version            Print version and exit
   -n, --nfkc               Normalize string according to Unicode v3.2 NFKC
   -p, --profile=STRING     Use specified stringprep profile instead
                             Valid stringprep profiles: `Nameprep',
                             `iSCSI', `Nodeprep', `Resourceprep', 
                             `trace', `SASLprep'
   -s, --stringprep         Prepare string according to nameprep profile
  -d, --punycode-decode    Decode Punycode
  -e, --punycode-encode    Encode Punycode
  -a, --idna-to-ascii      Convert to ACE according to IDNA (default mode)
  -u, --idna-to-unicode    Convert from ACE according to IDNA
 Cannot allocate memory Charset `%s'.
 Code points prohibited by top-level domain Command line interface to the internationalized domain name library.

All strings are expected to be encoded in the preferred charset used
by your locale.  Use `--debug' to find out what this charset is.  You
can override the charset used by setting environment variable CHARSET.

To process a string that starts with `-', for example `-foo', use `--'
to signal the end of parameters, as in `idn --quiet -a -- -foo'.

Mandatory arguments to long options are mandatory for short options too.
 Conflicting bidirectional properties in input Error in stringprep profile definition Flag conflict with profile Forbidden leading or trailing minus sign (`-') Forbidden unassigned code points in input Input already contain ACE prefix (`xn--') Input does not start with ACE prefix (`xn--') Internationalized Domain Name (IDN) convert STRINGS, or standard input.

 Invalid input Malformed bidirectional string Missing input No top-level domain found in input Non-digit/letter/hyphen in input Output would be too large or too small Output would exceed the buffer space provided Prohibited bidirectional code points in input Prohibited code points in input Punycode failed String not idempotent under ToASCII String not idempotent under Unicode NFKC normalization String preparation failed String size limit exceeded Success System dlopen failed System iconv failed Try `%s --help' for more information.
 Type each input string on a line by itself, terminated by a newline character.
 Unicode normalization failed (internal error) Unknown error Unknown profile Usage: %s [OPTION]... [STRINGS]...
 could not convert from %s to UTF-8 could not convert from UCS-4 to UTF-8 could not convert from UTF-8 to %s could not convert from UTF-8 to UCS-4 idna_to_ascii_4z: %s idna_to_unicode_8z4z (TLD): %s idna_to_unicode_8z4z: %s input error malloc only one of -s, -e, -d, -a, -u or -n can be specified punycode_decode: %s punycode_encode: %s stringprep_profile: %s tld_check_4z (position %lu): %s tld_check_4z: %s Project-Id-Version: libidn 1.21
Report-Msgid-Bugs-To: bug-libidn@gnu.org
POT-Creation-Date: 2012-01-10 21:21+0100
PO-Revision-Date: 2011-04-28 20:17+0800
Last-Translator: Ji ZhengYu <zhengyuji@gmail.com>
Language-Team: Chinese (simplified) <i18n-zh@googlegroups.com>
Language: zh_CN
MIME-Version: 1.0
Content-Type: text/plain; charset=utf-8
Content-Transfer-Encoding: 8bit
       --allow-unassigned   切换 IDNA AllowUnassigned 标识(默认关闭)
      --usestd3asciirules  切换 IDNA UseSTD3ASCIIRules 标识(默认关闭)
       --debug              打印调试信息
      --quiet              处理时不显示信息
      --no-tld                不按 TLD 指定的规则检查字符串
                             仅对 --idna-to-ascii 和 --idna-to-unicode 有效
   -h, --help               打印此帮助并退出
  -V, --version            打印程序版本并退出
   -n, --nfkc               按 Unicode v3.2 NFKC 正规化字符串
   -p, --profile=STRING     使用指定的 stringprep 配置文件 代替
                             有效的 stringprep 配置文件: `Nameprep',
                             `iSCSI', `Nodeprep', `Resourceprep', 
                             `trace', `SASLprep'
   -s, --stringprep         按 nameprep 配置文件 准备字符串
  -d, --punycode-decode    解码 Punycode
  -e, --punycode-encode    编码 Punycode
  -a, --idna-to-ascii      按 IDNA 转换为 ACE (默认方式)
  -u, --idna-to-unicode    按 IDNA 从 ACE 转换
 无法分配内存 字符集‘%s’。
 顶级域不接受代码点 国际化域名库的命令行界面。.

所有的字符串都将以您所在区域的最合适的字符集进行编码。
使用‘--debug’可以找出这个字符集。
您可通过设置环境变量 CHARSET 来重设这一字符集。

要想处理以‘-’开始的字符串，如‘-foo’，请使用‘--’来标识
参数结束，例如‘idn --quiet -a -- -foo’。

长选项所必需的参数对于短选项来说也是必需的。
 输入中出现相互冲突的双向属性 Stringpref 配置文件定义出错 标识与配置文件冲突 不能使用‘-’作为起始或终止符 输入中不能出现未赋值的代码点 输入已经包含 ACE前缀(‘xn--’) 输入未以 ACE 前缀(‘xn--’)开头 字符串或是标准输入的国际化域名(IDN)转化。

 无效输入 双向字符串格式错误 输入缺失 输入中未发现顶级域 输入中出现非数字/字母/连字符 输出太大或太小 输入将溢出所提供的缓冲区 输入中不能出现双向的代码点 输入中不能出现代码点 Punycode 失败 ToASCII 中字符串不是幂等的 Unicode NFKC 正规化过程中字符串不是幂等的 预备字符串失败 字符串大小越界 成功 系统 dlopen 失败 系统 iconv 失败 尝试用‘%s --help’获取更多信息。
 输入时，每个字符串单占一行。
 Unicode 正规化失败(内部错误) 未知错误 未知的配置文件 用法: %s [选项]... [字符串]...
 无法将 %s 转为 UTF-8 无法将 UCS-4 转为 UTF-8 无法将 UTF-8 转为 %s 无法将 UTF-8 转为 UCS-4 idna_to_ascii_4z：%s idna_to_unicode_8z4z (TLD)：%s idna_to_unicode_8z4z：%s 输入错误 malloc 只能指定 -s, -e, -d, -a, -u 或是 -n 中的一个 punycode_decode: %s punycode_encode：%s stringprep_profile：%s tld_check_4z (位置 %lu)：%s tld_check_4z：%s 