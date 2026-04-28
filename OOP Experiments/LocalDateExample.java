import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

class LocalDateExample {
    public static void main(String[] args) {

        // Current date
        LocalDate currentDate = LocalDate.now();

        // Parsing from string
        LocalDate parsedDate = LocalDate.parse("2024-01-15");

        // Using of() method
        LocalDate specificDate = LocalDate.of(2023, 10, 5);

        // Operations
        LocalDate nextWeek = currentDate.plusDays(7);
        LocalDate lastMonth = currentDate.minusMonths(1);

        boolean isLeap = currentDate.isLeapYear();

        long daysBetween = ChronoUnit.DAYS.between(parsedDate, currentDate);

        int year = currentDate.getYear();
        int month = currentDate.getMonthValue();
        int day = currentDate.getDayOfMonth();

        System.out.println(currentDate);
        System.out.println(parsedDate);
        System.out.println(specificDate);
        System.out.println(nextWeek);
        System.out.println(lastMonth);
        System.out.println(isLeap);
        System.out.println(daysBetween);
        System.out.println(year + " " + month + " " + day);
    }
}