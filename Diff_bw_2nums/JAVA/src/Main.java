import java.io.*;
import com.google.gson.Gson;
import com.google.gson.stream.JsonReader;

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
    private int input1;
    private int input2;
    private int output;
    Boolean result;

    int getInput1() {
        return this.input1;
    }

    int getInput2() {
        return this.input2;
    }

    int getOutput() {
        return this.output;
    }

    void setInput1(int input1) {
        this.input1 = input1;
    }

    void setInput2(int input2) {
        this.input2 = input2;
    }

    void setOutput(int output) {
        this.output = output;
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
            boolean failures = false;
            double tolerance = 0.000001; 
            for (TestCase testCase : util.testcases) {
                int result = Diff_bw_2nums_test.test(testCase.getInput1(), testCase.getInput2());
                double absoluteDifference = Math.abs(result - testCase.getOutput());
                testCase.result = (absoluteDifference < tolerance);
                if (!testCase.result) {
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

