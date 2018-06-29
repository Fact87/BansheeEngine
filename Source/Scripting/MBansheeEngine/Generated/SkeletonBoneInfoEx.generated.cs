using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace BansheeEngine
{
	/// <summary>Contains internal information about a single bone in a Skeleton.</summary>
	[StructLayout(LayoutKind.Sequential), SerializeObject]
	public partial struct BoneInfo
	{
		/// <summary>Unique name of the bone.</summary>
		public string name;
		/// <summary>Index of the parent bone (within the relevant Skeleton object). -1 if root bone.</summary>
		public int parent;
		/// <summary>Inverse transform of the pose the skeleton was initially created in.</summary>
		public Matrix4 invBindPose;
	}
}