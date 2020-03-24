#include "types.h"

namespace tg
{
	namespace io {
		class PointsReader;
		typedef tg::PointXYZINormalClassT<IntentType, IntenDim> OSGBPoint;
		class PointVisitor {
		public:
			PointVisitor();

			virtual ~PointVisitor() {};

			bool ReadFile(const std::string& i_filePath);

			int NextPoint(OSGBPoint& i_oPoint);	// >= 1 normal, 0 end, -1 error

			Point3F GetOffset();
			// TODO:����
			std::string GetSRSName();
			size_t GetNumOfPoints();

		private:
			std::shared_ptr<PointsReader> m_pointsReader;
		};
	}
}
