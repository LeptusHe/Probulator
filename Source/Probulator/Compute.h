#pragma once

#ifdef __APPLE__
#include "OpenCL/opencl.h"
#else
#include "CL/cl.h"
#include "CL/cl_ext.h"
#endif

#include <string>
#include <vector>

namespace Probulator
{
	struct ComputeDevice
	{
		cl_device_id id;

		std::string name;
		cl_bool available;
		cl_device_type type;
	};

	class ComputeKernel
	{
	public:

		ComputeKernel(const char* code, const char* name, cl_device_id deviceId);
		~ComputeKernel();

		cl_kernel getKernel() const { return m_kernel; }
		size_t getWorkGroupSize() const { return m_workGroupSize; }

	private:

		cl_program m_program = nullptr;
		cl_kernel m_kernel = nullptr;
		size_t m_workGroupSize = 0;
	};

}
