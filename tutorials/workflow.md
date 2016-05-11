### Markdown to pdf workflow

Example input file: `poster.md`

1. Edit markdown for printing (adjust headings and remove links)

2. Convert markdown to html:
   ```
   grip --title "" poster.md --export poster.html
   ```

3. Manually edit html to adjust top margin to 15px

4.  Convert html to a pdf:
   ```
   wkhtmltopdf --page-height "740mm" --page-width "210mm" poster.html poster.pdf
   ```
5. Adjust the page height to fit on one long page.

6. Send pdf to the printers. Guild Print and Design can only print up to 1.5 meters in length.
