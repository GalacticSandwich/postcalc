/**
    @file pcalc-err.h
    @author GalacticSandwich
    This header contains the declarations for functions designed to handle specialized error output, where
    proper error messages are generated, and exit codes are passed on to the main program.
*/

/**
    Passes an error message out to the specified error output stream in the content file, and then exits with
    the specified exit code. Error messages handled by a helper function inside the content file.
    @param code the exit code to pass
*/
void escape(const unsigned code);
