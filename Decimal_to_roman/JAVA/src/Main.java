import com.google.gson.Gson;
import com.google.gson.stream.JsonReader;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

class Config {
    private String testcasesFile;
    private String JavaResultFile;

    String getTestCaseFile() {
        return this.testcasesFile;
    }

    String getOutputFile() {
        return this.JavaResultFile;
    }

    public void setTestCaseFile(String testcasesFile) {
        this.testcasesFile = testcasesFile;
    }

    public void setJavaResultFile(String javaResultFile) {
        JavaResultFile = javaResultFile;
    }
}

class TestCase {
    private int input;
    private String output;
    Boolean result;

    int getInput() {
        return this.input;
    }

    String getOutput() {
        return this.output;
    }

    public boolean getResult() {
        return result;
    }

    public void setResult(boolean result) {
        this.result = result;
    }

    public String toString() {
        return "Input: " + input + " Output: " + output;
    }
}

class Util {
    TestCase[] testcases;
    Config config;
    Gson gson;

    Util() {
        this.gson = new Gson();
        this.config = readConfig();
        this.testcases = readTestcases();
    }

    private Config readConfig() {
        Config config = null;
        try {
            File file = new File("../../conf/config.json");
            JsonReader r = new JsonReader(new FileReader(file.getAbsolutePath()));
            config = gson.fromJson(r, Config.class);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return config;
    }

    private TestCase[] readTestcases() {
        TestCase[] testcases = null;
        try {
            File file = new File("../../" + config.getTestCaseFile());
            JsonReader reader = new JsonReader(new FileReader(file.getAbsolutePath()));
            testcases = gson.fromJson(reader, TestCase[].class);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return testcases;
    }

    public void writeTestCases() {
        try {
            File file = new File("../../" + config.getOutputFile());
            String json = gson.toJson(testcases);
            FileWriter writer = new FileWriter(file.getAbsolutePath());
            writer.write(json);
            writer.close();
            return;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Gson gson = new Gson();
        try {
            Util util = new Util();
            dec_to_romantest decToRomanTest = new dec_to_romantest();
            Boolean failures = false;
            for (TestCase testCase : util.testcases) {
                testCase.setResult(decToRomanTest.test(testCase.getInput(), testCase.getOutput()));
                if (!testCase.getResult()) {
                    failures = true;
                }
            }
            util.writeTestCases();
            if (failures) {
                System.exit(1);
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
