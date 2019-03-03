#----------------------------------------------------------------
# Create the external targets that our project relies on

# a list of all include directories
set( SHAKE_INCLUDE_DIRECTORIES 
	src/
    external/glm/
)

# a list of all external libraries
set( SHAKE_EXTERNAL_LIBRARIES 
	${EXECUTABLE_NAME}
)