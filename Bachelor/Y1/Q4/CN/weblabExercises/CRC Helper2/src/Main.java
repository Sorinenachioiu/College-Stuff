import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.*;

public class Main {

    public static void main(String[] args) throws IOException {
        // Reading input in the field input
        BufferedReader inputBuffer = new BufferedReader(new InputStreamReader(System.in));
        String input = inputBuffer.lines().collect(Collectors.joining("\n"));

        StringBuilder result = new StringBuilder();

        Scanner scanner = new Scanner(input);
        scanner.useDelimiter("\n");

        boolean multiLineStarted[] = new boolean[1];

        while(scanner.hasNext()){
            String currentLine = scanner.next();

            result.append(solveLine(currentLine, multiLineStarted));
            result.append("\n");
        }

        // This is a debug message
        System.err.println(input);


        // TODO: Add logic here


        // Print result
        System.out.println(result);

    }

    private static String solveLine(String currentLine, boolean[] alreadyInComment) {
        StringBuilder result = new StringBuilder();

        if (currentLine.contains("/*")) {
            alreadyInComment[0] = true;
        }

        if (!alreadyInComment[0]){
            String[] parts = currentLine.split("//", 2);
            String processedPart = processCode(parts[0]);
            result.append(processedPart);
            if (parts.length > 1) {
                result.append("//").append(parts[1]);
            }
        } else {
            result.append(currentLine);
        }

        if (currentLine.contains("*/")) {
            alreadyInComment[0] = false;
            if (currentLine.indexOf("*/") + 2 < currentLine.length()){
                String[] parts = currentLine.split("\\*/", 2);
                String processedPart = processCode(parts[1]);
                result = new StringBuilder(parts[0] + "*/" + processedPart);
            }
        }
        return result.toString();
    }

    private static String processCode(String codePart){
        Pattern classPattern = Pattern.compile("class\\s+(\\w+)");
        Matcher classMatcher = classPattern.matcher(codePart);
        while (classMatcher.find()){
            codePart = codePart.replace(classMatcher.group(1), "%" + classMatcher.group(1) + "%");
        }

        Pattern extendsPattern = Pattern.compile("extends\\s+(\\w+)");
        Matcher extendsMatcher = classPattern.matcher(codePart);
        while (extendsMatcher.find()){
            codePart = codePart.replace(extendsMatcher.group(1), "%" + extendsMatcher.group(1) + "%");
        }

        Pattern fieldPattern = Pattern.compile("(int|float|boolean)\\s+(\\w+);");
        Matcher fieldMatcher = fieldPattern.matcher(codePart);
        while (fieldMatcher.find()){
            codePart = codePart.replace(fieldMatcher.group(2), "^" + fieldMatcher.group(2) + "^");
        }
        return codePart;
    }

}
