import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.junit.jupiter.api.Assertions.assertEquals;

class MainTest {

    @ParameterizedTest
    @MethodSource("generator")
    public void fromRomaToGreeceTest(List<String> zaValuesToAdd, int result){
        assertEquals(Main.fromRomaToGreece(zaValuesToAdd), result);
    }

    public static Stream<Arguments> generator() {
        return Stream.of(
                Arguments.of(Arrays.asList("IV", ""), 0),

                Arguments.of(Arrays.asList("", "")),

                Arguments.of(Arrays.asList("", "")),

                Arguments.of(Arrays.asList("", "")),

                Arguments.of(Arrays.asList("", "")),

                Arguments.of(Arrays.asList("", "")),

                Arguments.of(Arrays.asList("", "")),

                Arguments.of(Arrays.asList("", ""))
        );
    }
}