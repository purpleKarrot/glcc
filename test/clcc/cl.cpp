#if 0

#define __CL_ENABLE_EXCEPTIONS

#include <clcc/cl.hpp>

#include <cstdio>
#include <cstdlib>
#include <iostream>

const char * helloStr = "__kernel void hello(void) {}";

int main(void)
{
	cl_int err = CL_SUCCESS;
	try
	{
		cl::platform_set platforms;
		std::cout << "Number of platforms: " << platforms.size() << std::endl;

		cl::Context context(CL_DEVICE_TYPE_CPU, 0, NULL, NULL, &err);

		std::vector<cl::device> devices =
				context.getInfo<CL_CONTEXT_DEVICES> ();

		cl::Program::Sources source(1, std::make_pair(helloStr,
				strlen(helloStr)));

		cl::Program program_ = cl::Program(context, source);

		program_.build(devices);

		cl::Kernel kernel(program_, "hello", &err);

		cl::CommandQueue queue(context, devices[0], 0, &err);
		cl::KernelFunctor func = kernel.bind(queue, cl::NDRange(4, 4),
				cl::NDRange(2, 2));

		func().wait();

	} catch (std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

#endif
