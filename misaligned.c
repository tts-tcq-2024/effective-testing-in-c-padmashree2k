#include <stdio.h>
#include <assert.h>
#include <string.h>

// Structure to hold color pair information
typedef struct {
    int index;
    char majorColor[10];
    char minorColor[10];
} ColorPair;

// Function to generate color map
int generateColorMap(ColorPair colorMap[25]) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    int colorIndex = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            colorMap[colorIndex].index = colorIndex;
            strncpy(colorMap[colorIndex].majorColor, majorColor[i], sizeof(colorMap[colorIndex].majorColor));
            strncpy(colorMap[colorIndex].minorColor, minorColor[j], sizeof(colorMap[colorIndex].minorColor));
            colorIndex++;
        }
    }
    
    return colorIndex;  // Return the total number of entries generated
}

// Mock function testing mechanism
int mockCallCount = 0;
int lastIndex = -1;
char lastMajorColor[10] = "";
char lastMinorColor[10] = "";

// Function to test the color map
void testColorMap(ColorPair colorMap[25]) {
    for (int i = 0; i < 25; i++) {
        mockCallCount++;
        lastIndex = colorMap[i].index;
        strncpy(lastMajorColor, colorMap[i].majorColor, sizeof(lastMajorColor));
        strncpy(lastMinorColor, colorMap[i].minorColor, sizeof(lastMinorColor));
    }
}

int main() {
    ColorPair colorMap[25];  // Array to hold the color map entries
    
    // Generate the color map
    int totalEntries = generateColorMap(colorMap);

    // Test the generated color map using the mock function
    testColorMap(colorMap);

    // Assertions to verify that the mock function was called correctly
    assert(mockCallCount == 25);  // Ensure that the test was called 25 times
    assert(lastIndex == 24);  // Check the last index passed to the mock function
    assert(strcmp(lastMajorColor, "Violet") == 0);  // Verify the last major color
    assert(strcmp(lastMinorColor, "Slate") == 0);  // Verify the last minor color

    printf("All tests passed! Generated color map works as expected.\n");
    return 0;
}
