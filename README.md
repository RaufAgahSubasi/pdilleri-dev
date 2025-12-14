# PD Ödev – 2B Matris Elemanına Row-Major Adres Hesaplayarak Erişim (C)

## Amaç
Bu ödevin amacı, programlama dillerinde iki boyutlu bir matrisin herhangi bir elemanına **yalnızca**:
- matrisin başlangıç adresi (**base address**),
- eleman boyutu (**byte** cinsinden),
- satır ve sütun sayıları (**rows, cols**),
- elemanın indeksleri (**i, j**)

kullanılarak erişimin nasıl yapıldığını öğretmektir.

Bu çalışmada **klasik `A[i][j]` dizinleme kullanılmadan**, **satır-öncelikli (row-major)** bellek düzenine göre adres hesaplanır; ilgili elemanın **bellek adresi** bulunur, bu adresteki **değer okunur** ve istenirse **güncellenir**. Tüm işlemler **pointer aritmetiği** ile gerçekleştirilir.

---

## Row-Major Adresleme Mantığı
C dilinde 2 boyutlu diziler (veya tek blok halinde tutulan matrisler) **row-major** düzende saklanır.  
Bu durumda `A[i][j]` elemanının başlangıca göre konumu:

- **Offset (eleman sayısı cinsinden):**
  
  `offset = i * cols + j`

- **Adres (byte cinsinden):**
  
  `address = base_address + offset * element_size`

- **Pointer aritmetiği ile:**
  
  `elemPtr = base + offset`

> Not: `base` işaretçisi `int*` ise `base + offset` ifadesi otomatik olarak `offset * sizeof(int)` kadar ilerler.

---

## Proje Ne Yapıyor?
- Matris için tek parça bellek ayırır (`malloc`)
- Matris elemanlarını pointer aritmetiğiyle doldurur (**A[i][j] yok**)
- Kullanıcıdan `(i, j)` alır
- `offset` ve **hesaplanan adresi** ekrana yazdırır
- Elemanın **mevcut değerini** okur ve yazdırır
- Kullanıcı yeni değer girerse elemanı **pointer üzerinden günceller**

---

## Dosyalar
- `main.c` : Ödevin C kodu
- `pdilleri.cbp` : Code::Blocks proje dosyası (varsa)

> Derleme çıktıları (`bin/`, `obj/`, `*.exe`, `*.o`) versiyon kontrolüne eklenmemelidir.

---

## Kurulum / Çalıştırma

### Code::Blocks ile
1. Projeyi aç (`.cbp`)
2. Build & Run (F9)

### Terminal (GCC) ile
```bash
gcc main.c -o pdilleri
./pdilleri
