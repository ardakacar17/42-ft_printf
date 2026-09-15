*This project has been created as part of the 42 curriculum by akacar.*

# ft_printf

## Açıklama
Bu projenin amacı, popüler ve oldukça kullanışlı olan C kütüphane fonksiyonu `printf()`'i yeniden yazmaktır. Proje, C dilindeki değişken sayıda argüman alan (variadic) fonksiyonların (`stdarg.h`) derinlemesine anlaşılmasını sağlarken; iyi yapılandırılmış, genişletilebilir ve Norminette kurallarına uygun kod yazma pratiğini pekiştirir.

Yazılan `ft_printf` fonksiyonu, orijinal fonksiyonun temel davranışlarını taklit ederek aşağıdaki dönüşümleri (conversions) başarıyla işler:
* `%c` - Tek bir karakter yazdırır.
* `%s` - Bir karakter dizisi (string) yazdırır.
* `%p` - Bir void pointer argümanını hexadecimal (on altılık) formatta yazdırır.
* `%d` / `%i` - İşaretli onluk (base 10) tabanda bir tam sayı yazdırır.
* `%u` - İşaretsiz (unsigned) onluk tabanda bir tam sayı yazdırır.
* `%x` - Hexadecimal (base 16) tabanda sayıyı küçük harflerle yazdırır.
* `%X` - Hexadecimal (base 16) tabanda sayıyı büyük harflerle yazdırır.
* `%%` - Yüzde işaretinin kendisini yazdırır.

## Algoritma ve Veri Yapısı
**Veri Yapısı:** Projede bağlı liste (linked list) gibi karmaşık harici veri yapılarına ihtiyaç duyulmamıştır. Sistemin temeli, fonksiyona gönderilen değişken sayıdaki argümanlar arasında güvenli bir şekilde gezinmek için `<stdarg.h>` kütüphanesinin sağladığı `va_list` yapısına dayanmaktadır.

**Algoritma:** Temel algoritma, tek geçişli bir metin ayrıştırma (string parsing) mekanizması üzerinde çalışır.
1. Format dizisi (string) karakter karakter döngüye sokulur.
2. Standart karakterler herhangi bir işleme tabi tutulmadan `write` fonksiyonu ile doğrudan ekrana basılır.
3. `%` karakteri ile karşılaşıldığında, sistemdeki "trafik polisi" yönlendirme fonksiyonu (`ft_format_check`) devreye girer. Bu fonksiyon, formattan istenen türü (örn. `s`, `d`, `x`) tespit eder ve `va_arg` ile alınan argümanı ilgili tek amaçlı, modüler yardımcı fonksiyona gönderir.
4. Sayı dönüşümleri (Onluk ve On altılık tabanlar) için, ekstra buffer (tampon) belleği tahsis etmeden (allocate) rakamları verimli bir şekilde işleyip yazdıran özyinelemeli (recursive) bir algoritma uygulanmıştır. 
5. Hexadecimal dönüşümlerde kapasite `unsigned long` olarak ayarlanmış, bu sayede hem standart 32-bit tam sayılar hem de 64-bit pointer bellek adresleri hiçbir veri kaybı yaşanmadan tek bir çatı altında işlenebilmiştir.

## Talimatlar

### Derleme
Kütüphaneyi derlemek için, terminalde proje dizinine giderek `make` komutunu çalıştırmanız yeterlidir. Bu işlem `libftprintf.a` statik kütüphanesini üretecektir.

```bash
make
```

Kullanılabilir Makefile kuralları:
* `make` veya `make all`: Kütüphaneyi derler.
* `make clean`: Derleme sırasında oluşan `.o` (object) dosyalarını siler.
* `make fclean`: Object dosyaları ile birlikte `libftprintf.a` kütüphanesini de siler.
* `make re`: Temizlik yapar ve kütüphaneyi baştan aşağı yeniden derler.

### Kullanım
Başlık dosyasını (header) kendi C projelerinize dahil edip, programınızı bu statik kütüphane ile derleyebilirsiniz.

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Merhaba, %s! Puanim %d.\n", "Dunya", 42);
    return (0);
}
```
Çalıştırılabilir dosyanızı üretmek için derleme komutu:
```bash
cc main.c libftprintf.a -o my_program
```

## Kaynaklar
* **Resmi Dokümantasyonlar:** `man 3 printf`, `man 3 stdarg`
* **Yapay Zeka (AI) Kullanım Beyanı:** 42 Yapay Zeka Yönergeleri (AI Instructions) gereğince, yapay zeka bir asistan olarak, bu projenin geliştirme aşamasında yalnızca temel bir öğrenme aracı şeklinde kullanılmıştır. Spesifik olarak yapay zekadan şu konularda destek alınmıştır:
  * Uç durumların (edge cases) beyin fırtınası (`NULL` metinler ve `0` pointer değerlerinin yönetimi).
  * Hexadecimal pointer dönüşümlerinde bellek kesintisini (truncation) önlemek amacıyla `unsigned int` ile `unsigned long` arasındaki kapasite sınırlarının hata ayıklaması (debugging).
  * Norminette'in mimari kısıtlamalarına (dosya başına maksimum 5 fonksiyon kuralı) uyum sağlama stratejileri.
  * *Not:* Yapay zeka hiçbir zaman kodun mantığını körü körüne oluşturmak için kullanılmamış; değişken argümanlı makroların (variadic macros) anlaşılmasını pekiştirmek ve modüler sistem yapısını doğrulamak için bir "peer-evaluator" (akran değerlendirici) rolü üstlenmiştir.