@call "%VS90COMNTOOLS%vsvars32.bat"
@echo creating NMake Makefiles
@cd build
@cmake -G "NMake Makefiles" ..
@cd ..
@pause
