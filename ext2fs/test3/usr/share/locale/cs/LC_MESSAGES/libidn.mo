��    ;      �  O   �        �   	  c   �  �     a   �  K   �  �   D  '  A     i	     �	  *   �	  �  �	  -   �  &   �     �  .     )   E  )   o  -   �  I   �               >  "   L      o  &   �  -   �  -   �          3  #   C  6   g     �     �     �     �     �  &     O   +  -   {     �     �  #   �  "   �  %     "   4  %   W     }     �     �     �     �     �  5   �     3     G     [     r     �  t  �  �     a   �  �   a  o   �  I   d    �  %  �     �     �  2     �  J  -   �  (     #   B  ;   f  7   �  .   �  -   	  \   7     �  )   �     �  #   �  7     8   <  ;   u  >   �  (   �       )   )  <   S     �  *   �     �      �       8     \   T  0   �     �     �  .         2   !   Q      s   !   �   $   �      �      �      !     &!     6!  G   =!  ,   �!  /   �!  8   �!     "     9"     7   6   )      -   &                     (   *   8                      1   ;         "   
          $           9   4                              3          +   2          5              /                     :   !                    0   #   %   	      ,   '                .              --allow-unassigned   Toggle IDNA AllowUnassigned flag (default off)
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
 could not convert from %s to UTF-8 could not convert from UCS-4 to UTF-8 could not convert from UTF-8 to %s could not convert from UTF-8 to UCS-4 could not do NFKC normalization idna_to_ascii_4z: %s idna_to_unicode_8z4z (TLD): %s idna_to_unicode_8z4z: %s input error malloc only one of -s, -e, -d, -a, -u or -n can be specified punycode_decode: %s punycode_encode: %s stringprep_profile: %s tld_check_4z (position %lu): %s tld_check_4z: %s Project-Id-Version: libidn 1.21
Report-Msgid-Bugs-To: bug-libidn@gnu.org
POT-Creation-Date: 2012-12-11 16:12+0100
PO-Revision-Date: 2011-04-28 20:24+0200
Last-Translator: Petr Pisar <petr.pisar@atlas.cz>
Language-Team: Czech <translation-team-cs@lists.sourceforge.net>
Language: cs
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
       --allow-unassigned   Přepne příznak IDNA AllowUnassigned (implicitně
                           vypnut)
      --usestd3asciirules  Přepne příznak IDNA UseSTD3ASCIIRules (implicitně
                           vypnut)
       --debug              Vypíše ladicí informace
      --quiet              Pracuje potichu
       --no-tld             Nekontroluje řetězec podle pravidel dané TLD.
                           Jen u --idna-to-ascii a --idna-to-unicode
   -h, --help               Vypíše nápovědu a skončí
  -V, --version            Vypíše verzi a skončí
   -n, --nfkc               Normalizuje řetězec podle Unicode v3.2 NFKC
   -p, --profile=ŘETĚZEC    Použije zadaný stringprep profil.
                           Platné stringprep profily jsou: „Nameprep“,
                           „iSCSI“, „Nodeprep“, „Resourceprep“, „trace“ a 
                           „SASLprep“
   -s, --stringprep         Připraví řetězec podle nameprep profilu
  -d, --punycode-decode    Dekóduje Punycode
  -e, --punycode-encode    Kóduje do Punycode
  -a, --idna-to-ascii      Převede do ACE podle IDNA (implicitní režim)
  -u, --idna-to-unicode    Převede z ACE podle IDNA
 Nelze vyhradit paměť Znaková sada „%s“.
 Ordinární čísla zakázaná vrcholovou doménou Rozhraní ke knihovně internacionalizovaných (s národními znaky) doménových
jmen pro prostředí příkazového řádku.

Všechny řetězce jsou očekávány ve znakové sadě upřednostňované vaším
národním prostředím. Která sada to je, zjistíte přepínačem „--debug“. Jinou
znakovou sadu můžete vnutit nastavením proměnné prostředí CHARSET.

Je-li třeba pracovat s řetězcem začínající znakem „-“ (např. „-foo“), použijte
„--“ pro označení konce všech parametrů (např. „idn --quiet -a -- -foo“).

Povinné argumenty dlouhých přepínačů jsou rovněž povinné u odpovídajících
krátkých přepínačů.
 Na vstupu rozporné příkazy pro směr textu Chyba v definici profilu pro stringprep Příznak neslučitelný s profilem Zakázaný úvodní nebo závěrečný spojovník („-“) Na vstupu zakázaná nepřiřazená ordinární čísla Vstup již obsahuje předponu ACE („xn--“) Vstup nezačíná předponou ACE („xn--“) IDN (internacionalizovaná doménová jména) převádí ŘETĚZCE nebo standardní vstup.

 Neplatný vstup Chybně utvořený obousměrný řetězec Postrádám vstup Ve vstupu chybí vrcholová doména Znak jiný než číslice/písmeno/spojovník na vstupu Výstup by byl příliš dlouhý nebo příliš krátký Výstup by se nevešel do poskytnuté vyrovnávací paměti Na vstupu zakázaná ordinární čísla pro obousměrný text Na vstupu zakázaná ordinární čísla Punycode selhal Řetězec není po ToASCII idempotentní Řetězec není po unicodové NFKC normalizaci idempotentní Příprava řetězce selhala Omezení délky řetězce bylo překonáno Úspěch Selhalo volání systému dlopen Selhal systémový iconv Další informace získáte příkazem „%s --help“.
 Pište po jednom vstupním řetězci na jednom řádku zakončeným znakem nového řádku.
 Unicodová normalizace selhala (vnitřní chyba) Neznámá chyba Neznámý profil Použití: %s [PŘEPÍNAČ]… [ŘETĚZEC]…
 nelze převést z %s do UTF-8 nelze převést z UCS-4 do UTF-8 nelze převést z UTF-8 do %s nelze převést z UTF-8 do UCS-4 nebylo možné znormalizovat do NFKC idna_to_ascii_4z: %s idna_to_unicode_8z4z (TLD): %s idna_to_unicode_8z4z: %s chyba na vstupu malloc Pouze jeden přepínač z -s, -e, -d, -a, -u nebo -n smí být zadán. punycode_decode (dekódování Punycodu): %s punycode_encode (zakódování do Punycodu): %s stringprep_profile (profil pro přípravu řetězce): %s tld_check_4z (pozice %lu): %s tld_check_4z: %s 