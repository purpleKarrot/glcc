/*! \class CommandQueue
 * \brief CommandQueue interface for cl_command_queue.
 */
class CommandQueue: public detail::Wrapper<cl_command_queue>
{
public:
	CommandQueue(const Context& context, const cl::device& device,
			cl_command_queue_properties properties = 0, cl_int* err = NULL)
	{
		cl_int error;
		object_ = ::clCreateCommandQueue(context(), device.id_, properties,
				&error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
	}

	//! Default constructor; command queue is not valid at this point.
	CommandQueue()
	{
	}

	template<typename T>
	void getInfo(cl_command_queue_info name, T* param) const
	{
		CLCC_CHECK_ERROR(detail::getInfo(&::clGetCommandQueueInfo, object_,
				name, param));
	}

	template<cl_int name>
	typename detail::param_traits<detail::cl_command_queue_info, name>::param_type //
	getInfo(cl_int* err = NULL) const
	{
		typename detail::param_traits<detail::cl_command_queue_info, name>::param_type
				param;
		cl_int result = getInfo(name, &param);
		if (err != NULL)
		{
			*err = result;
		}
		return param;
	}

	void setProperty(cl_command_queue_properties properties, cl_bool enable,
			cl_command_queue_properties* old_properties = NULL) const
	{
		CLCC_CHECK_ERROR(::clSetCommandQueueProperty(object_, properties,
				enable, old_properties));
	}

	void enqueueReadBuffer(const Buffer& buffer, cl_bool blocking,
			::size_t offset, ::size_t size, void* ptr,
			const VECTOR_CLASS<Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueReadBuffer(object_, buffer(), blocking,
				offset, size, ptr, (events != NULL) ? (cl_uint) events->size()
						: 0, (events != NULL) ? (cl_event*) &events->front()
						: NULL, (cl_event*) event));
	}

	void enqueueWriteBuffer(const Buffer& buffer, cl_bool blocking,
			::size_t offset, ::size_t size, void* ptr,
			const VECTOR_CLASS<Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueWriteBuffer(object_, buffer(), blocking,
				offset, size, ptr, (events != NULL) ? (cl_uint) events->size()
						: 0, (events != NULL) ? (cl_event*) &events->front()
						: NULL, (cl_event*) event));
	}

	void enqueueCopyBuffer(const Buffer& src, const Buffer& dst,
			::size_t src_offset, ::size_t dst_offset, ::size_t size,
			const VECTOR_CLASS<Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueCopyBuffer(object_, src(), dst(),
				src_offset, dst_offset, size,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueReadImage(const Image& image, cl_bool blocking,
			const size_3_t& origin, const size_3_t& region, ::size_t row_pitch,
			::size_t slice_pitch, void* ptr, const VECTOR_CLASS<Event>* events =
					NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueReadImage(object_, image(), blocking,
				origin.data(), region.data(), row_pitch, slice_pitch, ptr,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueWriteImage(const Image& image, cl_bool blocking,
			const size_3_t& origin, const size_3_t& region, ::size_t row_pitch,
			::size_t slice_pitch, void* ptr, const VECTOR_CLASS<Event>* events =
					NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueWriteImage(object_, image(), blocking,
				origin.data(), region.data(), row_pitch, slice_pitch, ptr,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueCopyImage(const Image& src, const Image& dst,
			const size_3_t& src_origin, const size_3_t& dst_origin,
			const size_3_t& region, const VECTOR_CLASS<Event>* events = NULL,
			Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueCopyImage(object_, src(), dst(),
				src_origin.data(), dst_origin.data(), region.data(), (events
						!= NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueCopyImageToBuffer(const Image& src, const Buffer& dst,
			const size_3_t& src_origin, const size_3_t& region,
			::size_t dst_offset, const VECTOR_CLASS<Event>* events = NULL,
			Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueCopyImageToBuffer(object_, src(), dst(),
				src_origin.data(), region.data(), dst_offset,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueCopyBufferToImage(const Buffer& src, const Image& dst,
			::size_t src_offset, const size_3_t& dst_origin,
			const size_3_t& region, const VECTOR_CLASS<Event>* events = NULL,
			Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueCopyBufferToImage(object_, src(), dst(),
				src_offset, dst_origin.data(), region.data(),
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void* enqueueMapBuffer(const Buffer& buffer, cl_bool blocking,
			cl_map_flags flags, ::size_t offset, ::size_t size,
			const VECTOR_CLASS<Event>* events = NULL, Event* event = NULL,
			cl_int* err = NULL) const
	{
		cl_int error;
		void * result = ::clEnqueueMapBuffer(object_, buffer(), blocking,
				flags, offset, size,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event, &error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
		return result;
	}

	void* enqueueMapImage(const Image& buffer, cl_bool blocking,
			cl_map_flags flags, const size_3_t& origin, const size_3_t& region,
			::size_t * row_pitch, ::size_t * slice_pitch, const VECTOR_CLASS<
					Event>* events = NULL, Event* event = NULL, cl_int* err =
					NULL) const
	{
		cl_int error;
		void * result = ::clEnqueueMapImage(object_, buffer(), blocking, flags,
				origin.data(), region.data(), row_pitch, slice_pitch, (events
						!= NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event, &error);

		CLCC_CHECK_ERROR(error);
		if (err != NULL)
		{
			*err = error;
		}
		return result;
	}

	void enqueueUnmapMemObject(const Memory& memory, void* mapped_ptr,
			const VECTOR_CLASS<Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueUnmapMemObject(object_, memory(),
				mapped_ptr, (events != NULL) ? (cl_uint) events->size() : 0,
				(events != NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueNDRangeKernel(const Kernel& kernel, const NDRange& offset,
			const NDRange& global, const NDRange& local, const VECTOR_CLASS<
					Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueNDRangeKernel(object_, kernel(),
				(cl_uint) global.dimensions(),
				offset.dimensions() != 0 ? (const ::size_t*) offset : NULL,
				(const ::size_t*) global,
				local.dimensions() != 0 ? (const ::size_t*) local : NULL,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueTask(const Kernel& kernel, const VECTOR_CLASS<Event>* events =
			NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueTask(object_, kernel(),
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueNativeKernel(void(*userFptr)(void *),
			std::pair<void*, ::size_t> args,
			const VECTOR_CLASS<Memory>* mem_objects = NULL, const VECTOR_CLASS<
					const void*>* mem_locs = NULL,
			const VECTOR_CLASS<Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueNativeKernel(object_, userFptr, args.first,
				args.second,
				(mem_objects != NULL) ? (cl_uint) mem_objects->size() : 0,
				(mem_objects != NULL) ? (const cl_mem *) &mem_objects->front()
						: NULL,
				(mem_locs != NULL) ? (const void **) &mem_locs->front() : NULL,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueMarker(Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueMarker(object_, (cl_event*) event));
	}

	void enqueueWaitForEvents(const VECTOR_CLASS<Event>& events) const
	{
		CLCC_CHECK_ERROR(::clEnqueueWaitForEvents(object_,
				(cl_uint) events.size(), (const cl_event*) &events.front()));
	}

	void enqueueAcquireGLObjects(
			const VECTOR_CLASS<Memory>* mem_objects = NULL, const VECTOR_CLASS<
					Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueAcquireGLObjects(object_, (mem_objects
				!= NULL) ? (cl_uint) mem_objects->size() : 0, (mem_objects
				!= NULL) ? (const cl_mem *) &mem_objects->front() : NULL,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueReleaseGLObjects(
			const VECTOR_CLASS<Memory>* mem_objects = NULL, const VECTOR_CLASS<
					Event>* events = NULL, Event* event = NULL) const
	{
		CLCC_CHECK_ERROR(::clEnqueueReleaseGLObjects(object_, (mem_objects
				!= NULL) ? (cl_uint) mem_objects->size() : 0, (mem_objects
				!= NULL) ? (const cl_mem *) &mem_objects->front() : NULL,
				(events != NULL) ? (cl_uint) events->size() : 0, (events
						!= NULL) ? (cl_event*) &events->front() : NULL,
				(cl_event*) event));
	}

	void enqueueBarrier() const
	{
		CLCC_CHECK_ERROR(::clEnqueueBarrier(object_));
	}

	void flush() const
	{
		CLCC_CHECK_ERROR(::clFlush(object_));
	}

	void finish() const
	{
		CLCC_CHECK_ERROR(::clFinish(object_));
	}
};
